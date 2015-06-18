//
//  ViewController.m
//  SampleApplication
//
//  Created by Patil, Nivedita on 6/18/15.
//  Copyright (c) 2015 Limelight Networks, Inc. All rights reserved.
//

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
