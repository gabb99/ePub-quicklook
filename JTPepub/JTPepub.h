//
//  JTPepub.h
//  epub
//
//  Created by Jake TM Pearce on 21/04/2011.
//  Copyright 2011 Imperial College. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GDataXMLNode.h"
#include <AppKit/AppKit.h>
#include "ZipArchive/ZipArchive.h"

struct MOBIData;

typedef enum {
    jtpUnknownBook = 0,
    jtpEPUB2,
    jtpEPUB3,
    jtpiBooks,
    jtpMobi
} JTPbookType;

@interface JTPepub : NSObject {
@private
    ZipArchive *epubFile;
    struct MOBIData *mobiFile;

    JTPbookType bookType;
    NSInteger epubVersion;

    NSMutableArray *manifest;
    NSMutableString *capturing;
    NSDictionary *entities;
    NSString *title;
    NSArray *authors;
    NSString *publisher;
    NSMutableArray *creators;
    NSArray *editors;
    NSArray *illustrators;
    NSArray *translators;
    NSString *synopsis;
    NSString *rootFilePath;
    NSString *ISBN;
    GDataXMLDocument *opfXML;
    NSImage *cover;
    BOOL haveCheckedForCover;
    NSDate *publicationDate;
    NSMutableArray *language;
    NSString *drm;
    NSDate *expiryDate;
}
- (id)initWithFile:(NSString *)fileName;
- (BOOL)openEPUBFile:(NSString*)fileName;

- (NSString *)textFromManifestItem:(NSUInteger)n;
- (NSString *)title;
- (NSArray *)authors;
- (NSString *)publisher;
- (NSArray *)creators;
- (NSArray *)editors;
- (NSArray *)illustrators;
- (NSArray *)translators;
- (NSImage *)cover;
- (NSString *)synopsis;
- (NSDate *)publicationDate;
- (NSString *)isbn;
- (NSString *)drm;
- (NSDate *)expiryDate;
- (NSArray *)language;

@end
