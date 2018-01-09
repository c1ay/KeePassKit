//
//  KPKKey.h
//  KeePassKit
//
//  Created by Michael Starke on 07/09/16.
//  Copyright © 2016 HicknHack Software GmbH. All rights reserved.
//

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@interface KPKKey : NSObject

@property (nonatomic, nullable, readonly, copy) NSData *data;

+ (instancetype)keyWithContentOfURL:(NSURL *)url;
+ (instancetype)keyWithPassword:(NSString *)password;

- (instancetype)initWithPassword:(NSString *)password;
- (instancetype)initWithContentOfURL:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END
