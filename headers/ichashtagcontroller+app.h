//
//  ICHashtagController+App.h
//  Ironcade
//
//  Created by Yangyang Wu on 12/8/20.
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <NotesUI/NotesUI.h>

#if TARGET_OS_OSX
#import "ICAutoCompleteSuggestionsViewController.h"
#endif

NS_ASSUME_NONNULL_BEGIN

extern NSUInteger const kICHashtagMaxLength;

#if TARGET_OS_IPHONE
@interface ICHashtagController (App)
#elif TARGET_OS_OSX
@interface ICHashtagController (App) <ICAutoCompleteSuggestionsViewControllerDelegate>
#endif

- (void)insertHashtagWithText:(NSString *)string viaAutoComplete:(BOOL)viaAutoComplete parentAttachment:(nullable ICAttachment *)parentAttachment;

+ (NSRange)rangeOfUnconfirmedHashtagInTextStorage:(TTTextStorage *)textStorage;

#if TARGET_OS_OSX
- (void)clearAutoCompletionView;
- (void)currentRowSelected;
- (BOOL)isAutoCompletionViewVisible;
- (void)performArrowUp;
- (void)performArrowDown;
- (void)performEscapeKey;
#endif

@end

NS_ASSUME_NONNULL_END

