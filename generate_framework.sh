#!/bin/sh

# ――― Check xcworkspace file ――― #
function xcworkspace_exists() {
    file_path=$(file_path_xcworkspace)
    file_name=$(basename "$file_path")
    if [ -d "$file_path" ]; then
        echo "Found $file_name"
        return 0 #true
    else
        echo "Unable to find *.xcworkspace"
        if podfile_exists; then
            echo "Installing cocoapods"
            pod install
            echo "Found $file_name"
            return 0 #true
        else
            echo "Failed to locate *.xcworkspace"
            echo "Aborting execution"
            exit 1
            return 1 #false
        fi
    fi
}

# ――― Get path of *.xcworkspace ――― #
function file_path_xcworkspace() {
    file_path=$(find . -maxdepth 1 -type d -name "*.xcworkspace")
    echo "$file_path"
}

# ――― Check Podfile ――― #
function podfile_exists() {
    podfile=$(find . -maxdepth 1 -name "Podfile")
    if [ -f "$podfile" ]; then
        return 0
    else
        return 1
    fi
}

# ――― Get file name from *.xcworkspace ――― #
function file_base_name() {
    file_path=$(file_path_xcworkspace)
    file_name=$(basename "$file_path")
    file_name_without_extension="${file_name%.*}"
    echo "$file_name_without_extension"
}

# ――― Create xcframework ――― #
function create_xcframework() {
    name=$(file_base_name)
    printf "\n"
    printf ".::Archiving $name.xcworkspace!::."
    printf "\n"
    xcodebuild archive \
    -workspace $name.xcworkspace \
    -scheme $name \
    -configuration Release \
    -destination "generic/platform=iOS" \
    -archivePath "Archives/$name-ios" \
    SKIP_INSTALL=NO \
    BUILD_LIBRARIES_FOR_DISTRIBUTION=YES;

    if [ $? -ne 0 ]; then
        echo "xcodebuild archive failed"
        exit 1
    fi

    xcodebuild archive \
    -workspace $name.xcworkspace \
    -scheme $name \
    -configuration Release \
    -destination "generic/platform=iOS Simulator" \
    -archivePath "Archives/$name-simulator" \
    SKIP_INSTALL=NO \
    BUILD_LIBRARIES_FOR_DISTRIBUTION=YES;

    if [ $? -ne 0 ]; then
        echo "xcodebuild archive failed"
        exit 1
    fi

    xcodebuild -create-xcframework \
    -archive Archives/$name-ios.xcarchive -framework $name.framework \
    -archive Archives/$name-simulator.xcarchive -framework $name.framework \
    -output $name.xcframework;

    if [ $? -ne 0 ]; then
        echo "xcodebuild create xcframework failed"
        exit 1
    fi
}

# ――― Delete existing file/folder frameworks ――― #
function delete_existing_frameworks() {
    printf "\n"
    echo "deleting existing framework"
    printf "\n"
    base_name=$(file_base_name)
    find . -type d -name "Archives" -exec rm -rf {} \;
    find . -type d -name "artifactory" -exec rm -rf {} \;
    find . -type d -name "$base_name.xcframework" -exec rm -rf {} \;
}

# ――― Zip xcframework ――― #
function zip_xcframework() {
    base_name=$(file_base_name)
    tag={TAG}
    zip_name="$base_name-Framework-$tag"
    printf "\n"
    echo "zipping %$base_name to $zip_name.zip"
    zip -r "$zip_name.zip" $base_name.xcframework
    mkdir artifactory
    mv "$zip_name.zip" artifactory
    echo "Successfully zipped file in artifactory folder"
}

# ――― Closing ――― #
function closing() {
    rm -r Archives

    echo " ╔═══════════════════════╗"
    echo " ║ Done! You're all set! ║"
    echo " ╚═══════════════════════╝"
}

# ――― Execution ――― #
function execution() {
    if xcworkspace_exists; then
        delete_existing_frameworks
        create_xcframework
        zip_xcframework
        closing
    fi
}

execution