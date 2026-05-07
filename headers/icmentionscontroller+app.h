//
//  ICMentionsController+App.h
//  Notes
//
//  Created by Harold Ho on 10/7/20.
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <NotesUI/NotesUI.h>
#if TARGET_OS_OSX
#import "ICAutoCompleteSuggestionsViewController.h"
#import "ICMacTextView.h"
#endif
#import "Notes-Swift.h"

@class ICAttachmentInsertionController;

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IPHONE
@interface ICMentionsController (App)
#elif TARGET_OS_OSX
@interface ICMentionsController (App) <ICAutoCompleteSuggestionsViewControllerDelegate>

- (void)clearAutoCompletionView;
- (void)currentRowSelected;
- (BOOL)isAutoCompletionViewVisible;
- (void)performArrowUp;
- (void)performArrowDown;
- (void)performEscapeKey;
#endif

@end

NS_ASSUME_NONNULL_END
