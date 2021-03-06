/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2012 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */
#import "TiProxy.h"
#import <Opentok/OTSubscriber.h>
#import "ComTokboxTiOpentokSubscriberViewProxy.h"

@class ComTokboxTiOpentokSessionProxy, ComTokboxTiOpentokStreamProxy;

@interface ComTokboxTiOpentokSubscriberProxy : TiProxy <OTSubscriberDelegate> {

@private
    // Owned
    OTSubscriber *_subscriber;
    ComTokboxTiOpentokSubscriberViewProxy *_subscriberViewProxy;
    // Unsafe unretained
    ComTokboxTiOpentokSessionProxy *_sessionProxy;
    ComTokboxTiOpentokStreamProxy *_streamProxy;
}

- (id)initWithSessionProxy:(ComTokboxTiOpentokSessionProxy *)sessionProxy 
                    stream:(ComTokboxTiOpentokStreamProxy *)stream 
                     audio:(BOOL)subscribeToAudio 
                     video:(BOOL)subscribeToVideo;

// Obj-C only Methods
- (OTSubscriber *)_subscriber;

// Properties
@property (readonly, assign) ComTokboxTiOpentokSessionProxy *session;
@property (readonly, assign) ComTokboxTiOpentokStreamProxy *stream;
@property (readonly) NSNumber *subscribeToAudio;
@property (readonly) NSNumber *subscribeToVideo;
@property (readonly) ComTokboxTiOpentokSubscriberViewProxy *view;

// Methods
-(void)close:(id)args;
-(ComTokboxTiOpentokSubscriberViewProxy *)createView:(id)args;

@end
