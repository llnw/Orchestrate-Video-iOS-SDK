Pod::Spec.new do |s|
s.name     = 'LimelightVideoKit'
  s.version  = '1.0.0'
  s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
        Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.

        http://www.limelight.com/tos/
      LICENSE
  }
  s.summary  = 'The Limelight Video Platform iOS Software Development Kit.'
  s.platform = :ios, '7.0'
  s.requires_arc = true
  s.homepage = 'http://support.video.limelight.com'
  s.author   = { 'Limelight Networks' => 'support@llnw.com' }
  s.source   = { :git => 'https://github.com/llnw/OrchestrateVideo-iOS-SDK.git',
                 :tag => s.version.to_s}
  s.source_files = 'Headers/*.h'
  s.vendored_libraries = "Library/libLimelightVideoKitUniversal.a"
  s.frameworks = 'AVFoundation', 'CFNetwork', 'CoreData', 'CoreMedia', 'CoreGraphics', 'MediaPlayer', 'MobileCoreServices', 'SystemConfiguration', 'UIKit'
  s.dependency 'AFNetworking', '~> 1.3'
  s.dependency 'Base64nl', '~> 1.1'
  s.dependency 'CocoaLumberjack', '~> 1.6'
  s.dependency 'Mantle', '~> 1.3.1'
  s.dependency 'OBSlider', '~> 1.1'
  s.dependency 'Reachability', '~> 3.1'
  s.dependency 'ReactiveCocoa', '~> 2.1'
  s.dependency 'Widevine-iOS-SDK', '~> 6.0.0'
end
