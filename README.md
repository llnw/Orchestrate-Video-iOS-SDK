# Limelight Video Platform iOS SDK

## Installation

**To add LimelightVideoKit manually to your project use following steps.**

1.	Download LimelightVideoSDK for iOS from here (?)
2.	Add the Library and Headers folder to your project.
3.	In the “Build Phases” tab of your application target, add the following frameworks
  - ‘AVFoundation’
  -	‘CFNetwork’
  -	‘CoreData’
  -	‘CoreGraphics’
  -	‘CoreMedia’
  -	‘Foundation’
  -	‘MediaPlayer’
  -	‘MobileCoreServices’
  -	‘SystemConfiguration’
  -	‘UIKit’
  - ‘libLimelightVideoKitUniversal.a’

4.	On the “Build Settings” tab of your application target.
  -	Make sure that LimelightVideoKit SDK headers are in your application’s “Header Search Paths”.
  -	Add –ObjC to “Other Linker Flags”.
  
5.	Add following third party libraries to your project

|Library Name	|Version  |
|---------------|---------|
|AFNetworking	|1.3      |
|Base64nl	|1.1      |
|CocoaLumberjack|1.6      |
|Mantle 	|1.3.1    |
|OBSlider	|1.1      |
|Reachability	|3.1      |
|ReactiveCocoa  |2.1      |
|Widevine-iOS-SDK|6.0.0   |

Getting all these third party libraries manually is tedious task.
You can use CocoaPods to get these libraries.

Sample Podfile is as follows.
```
source 'https://github.com/CocoaPods/Specs.git' 
source 'git@github.llnw.net:llnw/PodSpecs.git' 

platform :ios, '8.0'  
xcodeproj '<Your_Project_Name>', 'Coverage' => :debug  

pod 'AFNetworking','~> 1.3' 
pod 'Base64nl', '~> 1.1' 
pod 'CocoaLumberJack', '~> 1.6' 
pod 'Mantle', '~> 1.3.1' 
pod 'OBSlider', '~>1.1' 
pod 'Reachability', '~>3.1' 
pod 'ReactiveCocoa', '~>2.1' 
pod 'Widevine-iOS-SDK', '~>6.0.0'
```
**To add LimelightVideoKit through CocoaPods ** 
The easiest way to add the SDK and its dependencies to your project is to use CocoaPods. 
If you do not have CocoaPods installed, see the installation instructions on the [CocoaPods](https://guides.cocoapods.org/using/getting-started.html) site.

Use sample Podfile and install all the required pods by using command ‘pod install’ in your application project directory.
Sample Podfile is as follows
```
source 'https://github.com/CocoaPods/Specs.git'
source 'git@github.llnw.net:llnw/PodSpecs.git'

platform :ios, '8.0'

xcodeproj 'lvk-ios-integration', 'Coverage' => :debug

pod 'LimelightVideoKit', :git => 'https://github.llnw.net/llnw/limelight-sdk-ios.git'

# Remove 64-bit build architecture from Pods targets
post_install do |installer|
  installer.project.targets.each do |target|
    target.build_configurations.each do |configuration|
      target.build_settings(configuration.name)['ARCHS'] = '$(ARCHS_STANDARD_32_BIT)'
    end
  end
end
```
