# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

target 'Zoloz' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks! :linkage => :static

  # Pods for Zoloz
  pod 'CommonZoloz', :git => 'https://gitlab46.bni.co.id/maverick-mobile/ios/features/common-zoloz.git', :branch => 'main'

end

post_install do |installer|
  installer.generated_projects.each do |project|
    project.targets.each do |target|
      target.build_configurations.each do |config|
        config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '11.0'
        config.build_settings["EXCLUDED_ARCHS[sdk=iphonesimulator*]"] = "arm64"
      end
    end
  end
end