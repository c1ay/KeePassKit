//
//  KPKHeaderFields.h
//  KeePassKit
//
//  Created by Michael Starke on 20.07.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef MacPass_KPKHeaderFields_h
#define MacPass_KPKHeaderFields_h

#import <Foundation/Foundation.h>

/**
 Header keys for KDBX files
 */
typedef NS_ENUM(NSUInteger, KPKHeaderKey ) {
  KPKHeaderKeyEndOfHeader,
  KPKHeaderKeyComment,
  KPKHeaderKeyCipherId,
  KPKHeaderKeyCompression,
  KPKHeaderKeyMasterSeed,
  KPKHeaderKeyTransformSeed,
  KPKHeaderKeyTransformRounds,
  KPKHeaderKeyEncryptionIV,
  KPKHeaderKeyProtectedKey,
  KPKHeaderKeyStartBytes,
  KPKHeaderKeyRandomStreamId
};

/**
 Field Types for KDB Filey
 */
typedef NS_ENUM(NSUInteger, KPKFieldType) {
  /* Common types */
  KPKFieldTypeCommonSize = 0,
  KPKFieldTypeCommonStop = 0xFFFF,
  /* Groups Types */
  KPKFieldTypeGroupId    = 1,
  KPKFieldTypeGroupName,
  KPKFieldTypeGroupCreationTime,
  KPKFieldTypeGroupModificationTime,
  KPKFieldTypeGroupAccessTime,
  KPKFieldTypeGroupExpiryDate,
  KPKFieldTypeGroupImage,
  KPKFieldTypeGroupLevel,
  KPKFieldTypeGroupFlags,
  /* Entry Types */
  KPKFieldTypeEntryUUID = 1,
  KPKFieldTypeEntryGroupId,
  KPKFieldTypeEntryImage,
  KPKFieldTypeEntryTitle,
  KPKFieldTypeEntryURL,
  KPKFieldTypeEntryUsername,
  KPKFieldTypeEntryPassword,
  KPKFieldTypeEntryNotes,
  KPKFieldTypeEntryCreationTime,
  KPKFieldTypeEntryModificationTime,
  KPKFieldTypeEntryAccessTime,
  KPKFieldTypeEntryExpiryDate,
  KPKFieldTypeEntryBinaryDescription,
  KPKFieldTypeEntryBinaryData,
};


#endif
