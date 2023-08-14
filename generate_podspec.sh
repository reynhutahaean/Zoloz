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

# ――― Delete current podspec file ――― #
function delete_current_podspec() {
    find . -type f -name "*.podspec" -exec rm {} \;
    echo "Current podspec was deleted"
}

# ――― Generate new podspec ――― #
function generate_new_podspec() {
    name=$(file_base_name)
    replacement=$(grep "pod '" Podfile | sed "s/pod '\([^']*\).*/spec.dependency '\1'/")
    repo_url=$(git ls-remote --get-url origin)
    tag={TAG}
    echo "Generating $name.podspec"
    pod spec create $name

        cat > "$name.podspec" << EOF
 Pod::Spec.new do |spec|
  spec.name         = "$name"
  spec.version      = "$tag"
  spec.summary      = "#{spec.name} framework."
  spec.description  = "Description for #{spec.name} framework."
  spec.homepage     = "https://gitlab46.bni.co.id/maverick-mobile/ios/"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "Maverick" => "" }
  spec.platform     = :ios, "11.0"

  system("curl --header 'PRIVATE-TOKEN: {TOKEN}' '{URL}' -O -k && unzip -d . {ZIP}")

  spec.source       = { :git => "$repo_url", :branch => "generate-podspec" }
  spec.ios.vendored_frameworks = '$name.xcframework'
  $replacement
end
EOF
printf "\n"
echo "Successfully generating $name.podspec"
}

# ――― Closing ――― #
function closing() {
    echo " ╔═══════════════════════╗"
    echo " ║ Done! You're all set! ║"
    echo " ╚═══════════════════════╝"
}

# ――― Execution ――― #
function execution() {
    if xcworkspace_exists; then
        delete_current_podspec
        generate_new_podspec
        closing
    fi
}

execution
