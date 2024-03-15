Pod::Spec.new do |spec|
	spec.name         = "testui"
	spec.version      = "0.0.9"
	spec.summary      = "Alyce Pose Ui framework"
	spec.description  = <<-DESC
Pose estimation and evaluation kit
                      DESC

	spec.homepage     = "https://not-needed-for-local-pod"
	spec.static_framework = true
	spec.swift_version    = '5'
	spec.license      = { :type => "MIT", :file => "LICENSE" }
  	spec.author             = { "ryan" => "dev.ryan.cha@gmail.com" }
	spec.ios.deployment_target = "14.0"

	spec.source       = { :git => "https://github.com/ios-momo/testui.git", :tag => "#{spec.version}" }
	spec.source_files  = "testui/testui.h", "testui/TestUIObject.swift", "src/**/*"
	spec.resource_bundles = { 'AlycePoseUiRes' => ['res/*.tflite', 'res/storyboards/*.storyboard'] }
	spec.vendored_frameworks = 'Frameworks/AlycePoseCore.xcframework'

	spec.dependency 'Alamofire', '~> 5.6.2'
	spec.dependency 'TensorFlowLiteSwift', '2.12.0'
	spec.dependency 'TensorFlowLiteSwift/CoreML', '2.12.0'
	spec.dependency 'TensorFlowLiteSwift/Metal', '2.12.0'
	spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end
