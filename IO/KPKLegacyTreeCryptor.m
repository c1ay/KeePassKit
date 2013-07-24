//
//  KPKLegacyDataCryptor.m
//  MacPass
//
//  Created by Michael Starke on 21.07.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//

#import "KPKLegacyTreeCryptor.h"
#import "KPKLegacyHeaderReader.h"
#import "KPKLegacyTreeReader.h"
#import "KPKPassword.h"
#import "KPKVersion.h"

#import "NSData+CommonCrypto.h"

#import <CommonCrypto/CommonCryptor.h>

@interface KPKLegacyTreeCryptor () {
  KPKLegacyHeaderReader *_headerReader;
}
@end

@implementation KPKLegacyTreeCryptor

- (id)initWithData:(NSData *)data passwort:(KPKPassword *)password {
  self = [super initWithData:data passwort:password];
  if(self) {
  }
  return self;
}

- (KPKTree *)decryptTree:(NSError *__autoreleasing *)error {
  _headerReader = [[KPKLegacyHeaderReader alloc] initWithData:_data error:error];
  
  // Create the final key and initialize the AES input stream
  NSData *keyData = [_password finalDataForVersion:KPKVersion1
                                        masterSeed:_headerReader.masterSeed
                                     transformSeed:_headerReader.transformSeed
                                            rounds:_headerReader.rounds];
  
  
  NSData *aesDecrypted = [[_headerReader dataWithoutHeader] decryptedDataUsingAlgorithm:kCCAlgorithmAES128
                                                                                        key:keyData
                                                                       initializationVector:_headerReader.encryptionIV
                                                                                    options:kCCOptionPKCS7Padding
                                                                                      error:NULL];
  
  KPKLegacyTreeReader *reader = [[KPKLegacyTreeReader alloc] initWithData:aesDecrypted headerReader:_headerReader];
  return [reader tree:error];
}

@end
