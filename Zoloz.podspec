 Pod::Spec.new do |spec|
  spec.name         = "Zoloz"
  spec.version      = "0.0.1"
  spec.summary      = "#{spec.name} framework."
  spec.description  = "Description for #{spec.name} framework."
  spec.homepage     = "https://gitlab46.bni.co.id/maverick-mobile/ios/"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "Maverick" => "" }
  spec.platform     = :ios, "11.0"

  system("curl --header 'PRIVATE-TOKEN: {TOKEN}' '{URL}' -O -k && unzip -d . {ZIP}")

  spec.source       = { :git => "https://github.com/reynhutahaean/Zoloz.git", :branch => "generate-podspec" }
  spec.ios.vendored_frameworks = 'Zoloz.xcframework'
    spec.dependency 'CommonZoloz'
end
