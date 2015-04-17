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
  
5.	Add sample Podfile to your project and install pods by using command ‘pod install’ in your application project directory.
