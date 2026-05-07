//
//  ICNotesActivityContinuationUtilities.h
//  Notes
//
//  Created by Jason Townsend on 10/2/14.
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <NotesUI/NotesUI.h>

@class ICNoteUserActivityState;
@class ICTextViewScrollState;

extern NSString *const ICNotesEditNoteUserActivityType;

extern NSString *const ICUserActivityInfoDictionaryNoteIDKey;
extern NSString *const ICUserActivityInfoDictionaryNoteModificationDateKey;
extern NSString *const ICUserActivityInfoDictionaryNoteCreationDateKey;
extern NSString *const ICUserActivityInfoDictionaryNoteIsEditingKey;
extern NSString *const ICUserActivityInfoDictionaryNoteOffsetKey;
extern NSString *const ICUserActivityInfoDictionaryNoteVisibleRangeDataKey;
extern NSString *const ICUserActivityInfoDictionaryNoteSelectionRangeDataKey;
extern NSString *const ICUserActivityInfoDictionaryNoteContentHashKey;
extern NSString *const ICUserActivityInfoDictionaryFolderIDKey;
extern NSString *const ICUserActivityInfoDictionaryFolderNameKey;
extern NSString *const ICUserActivityInfoDictionaryWantsContinuationStreams;

extern const NSTimeInterval ICPendingActivityContinuationTimeOut;

// YES if that note supports activity continuation (note needs to be synced).
BOOL ICNotesCanContinueActivityForNote(ICNote *note);

// YES if we can send the note content at handoff time to ensure it is fully synced.
BOOL ICNotesSupportsContinuationStreamsForNote(ICNote *note);

// YES if we can send the note content for this activity at handoff time to ensure it is fully synced.
BOOL ICNotesSupportsContinuationStreamsForUserActivity(NSUserActivity *activity);

// Update the userInfo dictionary of activity
void ICNotesUpdateUserActivityForViewingNoteWithState(NSUserActivity *activity, ICNoteUserActivityState *state);

// Returns the note mentioned by the activity. nil if an error occured (like if it's not found, code NotesErrorCantFindUserActivityNote, domain NotesErrorDomain).
ICNote *ICNotesGetNoteMentionedByActivity(NSUserActivity *activity, ICNoteContext *context, NSError * __autoreleasing*errPtr);

NSRange ICNotesGetVisibleRangeFromActivity(NSUserActivity *activity, ICNote *note);
ICTextViewScrollState *ICNotesGetScrollStateFromActivity(NSUserActivity *activity, ICNote *note);

NSArray *ICNotesGetSelectionRangesFromActivity(NSUserActivity *activity, ICNote *note);

// YES if the note was currently being edited.
BOOL ICNotesWasNoteEditingInActivity(NSUserActivity *activity);
