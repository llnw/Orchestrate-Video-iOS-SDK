# Limelight Video Platform iOS SDK

## Prerequisites

*	Target iOS 7 or 8
*	Xcode 6 or later
*	A Limelgiht Video Platform account 
    

## Installation

**To add LimelightVideoKit manually to your project use following steps.**

1.	Download LimelightVideoSDK for iOS from [here](https://github.com/llnw/OrchestrateVideo-iOS-SDK/releases/tag/1.0.0).
2.	Add the Library and Headers folder to your project.
3.	In the “Build Phases” tab of your application target, add the following frameworks
    *	‘AVFoundation’
    *	‘CFNetwork’
    *	‘CoreData’
    *	‘CoreGraphics’
    *	‘CoreMedia’
    *	‘Foundation’
    *	‘MediaPlayer’
    *	‘MobileCoreServices’
    *	‘SystemConfiguration’
    *	‘UIKit’
    *	 ‘libLimelightVideoKitUniversal.a’
4.	On the “Build Settings” tab of your application target.
    *	Make sure that LimelightVideoKit SDK headers are in your application’s “Header Search Paths”.
    *	Add –ObjC to “Other Linker Flags”.
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

	```objective-c
    	source 'https://github.com/CocoaPods/Specs.git' 
    	source 'https://github.com/llnw/PodSpecs.git' 

    	platform :ios, '8.0'  
    	xcodeproj '<YOUR_PROJECT_NAME>', 'Coverage' => :debug  

    	pod 'AFNetworking','~> 1.3' 
    	pod 'Base64nl', '~> 1.1' 
    	pod 'CocoaLumberJack', '~> 1.6' 
    	pod 'Mantle', '~> 1.3.1' 
    	pod 'OBSlider', '~>1.1' 
    	pod 'Reachability', '~>3.1' 
    	pod 'ReactiveCocoa', '~>2.1' 
    	pod 'Widevine-iOS-SDK', '~>6.0.0'
	```

**To add LimelightVideoKit through CocoaPods** 

The easiest way to add the SDK and its dependencies to your project is to use CocoaPods. 
If you do not have CocoaPods installed, see the installation instructions on the [CocoaPods](https://guides.cocoapods.org/using/getting-started.html) site.

1. 	Use sample Podfile and install all the required pods by using command ‘pod install’ in your application project directory.
    	The below text should be saved into a file named "Podfile":
    
	```objective-c
    	source 'https://github.com/CocoaPods/Specs.git'
    	source 'https://github.com/llnw/PodSpecs.git'

    	platform :ios, '8.0'

    	xcodeproj '<YOUR_PROJECT_NAME>', 'Coverage' => :debug

    	pod 'LimelightVideoKit'

    	# Remove 64-bit build architecture from Pods targets
    	post_install do |installer|
     	  installer.project.targets.each do |target|
            target.build_configurations.each do |configuration|
              target.build_settings(configuration.name)['ARCHS'] = '$(ARCHS_STANDARD_32_BIT)'
            end
      	  end
    	end
	```

2.	In the “Build Phases” tab of your application target, add the following frameworks if missing
	*  ‘AVFoundation’
	*  ‘CFNetwork'
	*  ‘CoreData’
	*  ‘CoreGraphics’
	*  ‘CoreMedia’
	*  ‘Foundation’
	*  ‘MediaPlayer’
	*  ‘MobileCoreServices’
	*  ‘SystemConfiguration’
	*  ‘UIKit’



3.	 On the “Build Settings” tab of your application target:
	*  Add –ObjC to “Other Linker Flags”.

##How to create Simple Application using LimelightVideoSDK 

This tutorial helps you create basic application using LimelightVideoSDK to play a sample media.

There are two ways to try this Sample Application.

1.	Manually setup the project by following the steps below.
2.	Download the sample project as a starting point from Github
	*  Get the entire project from [here](https://github.com/llnw/OrchestrateVideo-iOS-SDK/tree/master/SampleApplication).
	*  Run the ‘pod install’ command
	*  Open the newly created workspace.
	*  Replace placeholders in ViewController.m with appropriate values.
           e.g. Replace <YOUR_MEDIA_ID> with sample media ID you want to play.

###Create the project in Xcode.
If you do not have it already please install Xcode 6 or later.

1.	Create a new project in Xcode.
        Open Xcode and you will see screen as below.

	![Create New Project](Screenshots/Create New Project.png "Create a new project in Xcode 6 or later")

2.	Select **Single View Application** for the template and click **Next**.

	![Select Layout](Screenshots/Select Layout.png "Select Single View Application laylout")

3.	Set the project details as follows.

	> Product Name: SampleApplication
	>
	> Organization Name: 'YourCompanyName'
	>
	> Company Identifier: 'com.yourcompany'

   	![Specify project details](Screenshots/Project Details.png "Specify Project Details")

4.	Select the location where you want to save your project and click Create.
	You can select checkbox in front of ‘Source Control’ if you want to create a git repository for your project.

	![Select project location](Screenshots/Select Location .png "Select project location")

5.	Now close the project as we need to install pods and after that we will use ".xcworkspace" file created by that.

###Adding SDK and setting up your project for dependencies
The easiest way to add the SDK and its dependencies to your project is to use CocoaPods. If you do not have CocoaPods installed, see the installation instructions on the [CocoaPods](https://guides.cocoapods.org/using/getting-started.html) site.

6.	Use sample Podfile and install all the required pods by using command ‘pod install’ in your application project directory. 
	You should see series of messages in the terminal saying that LimelightVideoKit along with other third party libraries required for the SDK are installed.
	Sample Podfile is as follows.

	```objective-c
	source 'https://github.com/CocoaPods/Specs.git'
	source 'https://github.com/llnw/PodSpecs.git'

	platform :ios, '8.0'

	xcodeproj 'SampleApplication', 'Coverage' => :debug

	pod 'LimelightVideoKit'

	# Remove 64-bit build architecture from Pods targets
	post_install do |installer|
  	  installer.project.targets.each do |target|
    	    target.build_configurations.each do |configuration|
              target.build_settings(configuration.name)['ARCHS'] = '$(ARCHS_STANDARD_32_BIT)'
    	    end
          end
	end
	```

	You should see following line as last line.

	>[!] Please close any current Xcode sessions and use `SampleApplication.xcworkspace` for this project from now on.

	The ‘pod install’ creates .xcworkspace file. This step onwards you should use .xcworkspace to open your project.

If you do not wish to use CocoaPods then add LimelightVideoKit manually to your project by using following steps

6.	Download LimelightVideoSDK for iOS from [here](https://github.com/llnw/OrchestrateVideo-iOS-SDK/releases/tag/1.0.0).
7.	Add the Library and Headers folder to your project
8.	In the “Build Phases” tab of your application target, add the following frameworks
    *  ‘AVFoundation’
    *  ‘CFNetwork’
    *  ‘CoreData’
    *  ‘CoreGraphics’
    *  ‘CoreMedia'
    *  ‘Foundation’
    *  ‘MediaPlayer’
    *  ‘MobileCoreServices’
    *  ‘SystemConfiguration’
    *  ‘UIKit’
    *  ‘libLimelightVideoKitUniversal.a’

9.	On the “Build Settings” tab of your application target:
    *	Make sure that LimelightVideoKit SDK headers are in your application’s “Header Search Paths”.
    *	Add –ObjC to “Other Linker Flags”.

10.	Add following third party libraries to your project


	|Library Name   |Version  |
	|---------------|---------|
	|AFNetworking   |1.3      |
	|Base64nl       |1.1      |
	|CocoaLumberjack|1.6      |
	|Mantle         |1.3.1    |
	|OBSlider       |1.1      |
	|Reachability   |3.1      |
	|ReactiveCocoa  |2.1      |
	|Widevine-iOS-SDK|6.0.0   |

	Getting all these third party libraries manually is tedious task.
	You can use CocoaPods just to get these libraries.

	Sample Podfile is as follows.

	```objective-c
	source 'https://github.com/CocoaPods/Specs.git' 
	source 'https://github.com/llnw/PodSpecs.git' 

	platform :ios, '8.0'  
	xcodeproj '<YOUR_PROJECT_NAME>', 'Coverage' => :debug  

	pod 'AFNetworking','~> 1.3' 
	pod 'Base64nl', '~> 1.1' 
	pod 'CocoaLumberJack', '~> 1.6' 
	pod 'Mantle', '~> 1.3.1' 
	pod 'OBSlider', '~>1.1' 
	pod 'Reachability', '~>3.1' 
	pod 'ReactiveCocoa', '~>2.1' 
	pod 'Widevine-iOS-SDK', '~>6.0.0'
	```


### Code the simple videoplayer application
You are just few steps away from playing sample media in your application.

1.	Open the SampleApplication.xcworkspace file in Xcode.
2.	Go to ‘Build Settings’ of your application and make sure the architectures is set ‘$(ARCHS_STANDARD_32_BIT) - $(ARCHS_STANDARD_32_BIT)’. If not then, set it to 32 bit. Please check the same thing for Pods build settings as well.

	![Set architecture to 32 BIT](Screenshots/Architecture Settings.png "Set architecture to 32 BIT")
3.	Modify your ViewController implementation as given below.
     -	In ViewController.m file create placeholder variables for media and library as below before the implementation..
	
	```objective-c
	NSDictionary *media;
	LVKLibrary *library;
	```

     -	Define initialization method to setup sample media and library.
	Here you would need to give your Limelight Video Account credentials including OrganiztionId, access key and secret key and media ID.

	```objective-c
	+ (void)initialize {
    	    if(!media){
        	media = @{@"Sample Media":@"<YOUR_MEDIA_ID>"};
            }	
    	    if(!library){
      		library = [LVKLibrary 	libraryWithOrganizationId:@"<YOUR_ORG_ID>"
                  		                    	accessKey:@"<YOUR_ACCESS_KEY>"
                                  	            	   secret:@"<YOUR_SECRET_KEY"];   }
	}
	```

     -	"viewDidLoad" is automatically generated method. In viewDidLoad, add following code below the exisiting code.

	```objective-c
	[library fetchMediaForId:media[@"Sample Media"]
                     success:^(LVKMedia *media) {
                           LVKPlayerViewController *pvc = [LVKPlayerViewController playerForMedia:media];
                           [pvc.player prepareToPlay];
                           UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:pvc];
                           [self presentViewController:nav animated:YES completion:^{
                               NSLog(@"Player Successfully Loaded");
                           }];
                     } failure:^(NSError *error) {
                         NSLog(@"Media fetch error: %@", error);
                     }];
	```
     - 	At this point, compiler will complain about some of the unknown types.
       	> e.g. Unknown type name 'LVKLibrary'.
       	So we need to add missing header files as follows. 

       	```objective-c
       	#import "LVKLibrary.h"
       	#import "LVKLibrary+Media.h"
       	#import "LVKPlayerViewCOntroller.h"
       	#import "LVKPlayerController.h"
       	```
     -  After you follow all the steps, viewController.m should be as follows
	
	```objective-c
	#import "ViewController.h"
	#import "LVKLibrary.h"
	#import "LVKLibrary+Media.h"
	#import "LVKPlayerViewCOntroller.h"
	#import "LVKPlayerController.h"

	@interface ViewController ()

	@end

	NSDictionary *media;
	LVKLibrary *library;

	@implementation ViewController

	+ (void)initialize {
    	  if(!media){
        	media = @{@"Sample Media": @"<YOUR_MEDIA_ID>"};
    	  }	
    	  if(!library){
         	library = [LVKLibrary libraryWithOrganizationId:@"<YOUR_ORG_ID>"
                                              accessKey:@"<YOUR_ACCESS_KEY>"
                                                 secret:@"<YOUR_SECRET_KEY>"];
    	  }
	}
	- (void)viewDidLoad {
    	  [super viewDidLoad];
    	  // Do any additional setup after loading the view, typically from a nib.
    	  [library fetchMediaForId:media[@"Sample Media"]
                success:^(LVKMedia *media) {
                         LVKPlayerViewController *pvc = [LVKPlayerViewController playerForMedia:media];
                         [pvc.player prepareToPlay];
                         UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:pvc];
                         [self presentViewController:nav animated:YES completion:^{
                             NSLog(@"Player Successfully Loaded");
                         }];
                } failure:^(NSError *error) {
                         NSLog(@"Media fetch error: %@", error);
          }];
 
	}

	- (void)didReceiveMemoryWarning {
    	  [super didReceiveMemoryWarning];
    	  // Dispose of any resources that can be recreated.
	}

	@end
	```

4.	Run the application and you should be able to play the sample video.


