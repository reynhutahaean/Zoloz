Pod::Spec.new do |spec|
    spec.name         = "Zoloz"
    spec.version      = "0.0.1"
    spec.summary      = "#{spec.name} framework."
    spec.description  = "Description for #{spec.name} framework."
    spec.homepage     = "https://github.com/reynhutahaean"
    spec.license      = { :type => "MIT", :file => "LICENSE" }
    spec.author       = { "Reynhutahaean" => "" }
    spec.platform     = :ios, "11.0"
    spec.source       = { :git => "https://github.com/reynhutahaean/Zoloz.git", :branch => "main" }
    spec.source_files = "Zoloz/**/*.swift"
    spec.resources    = ["Zoloz/**/*.xib", "Zoloz/**/*.storyboard"]
    spec.resource_bundles = {
      'Zoloz' => ["Zoloz/**/*.xcassets", "Zoloz/*.xcassets"]
    }

    spec.dependency 'CommonZoloz'
  end
  