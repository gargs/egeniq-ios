//
//  EFDownloadQueue.h
//  iPortfolio
//
//  Created by Ivo Jansch on 8/27/10.
//  Copyright (c) 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EFDownload.h"

@interface EFDownloadQueue : NSObject {

    NSUInteger downloadConcurrency;
    NSUInteger downloadsRunning;
    
    NSMutableArray *queue;
    
    id delegate;
    
    BOOL queueStarted;
    
}

- (id)initWithConcurrency: (NSUInteger)concurrency;
- (NSUInteger) count;
- (void) start;
- (void) clear;
- (void) addDownload: (EFDownload *)download;
- (void) addPrioritizedDownload: (EFDownload *)download;

@property (assign) id delegate;

@end

@interface NSObject (EFDownloadQueueDelegateMethods)

- (void)queue: (EFDownloadQueue *)queue didQueueDownload:(EFDownload*)download;
- (void)queue: (EFDownloadQueue *)queue didFinishDownload:(EFDownload*)download;
- (void)queue: (EFDownloadQueue *)queue didFailDownload:(EFDownload*)download withError:(NSError*)error;


@end