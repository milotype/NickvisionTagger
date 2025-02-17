#pragma once

#include <adwaita.h>
#include "../../controllers/mainwindowcontroller.hpp"

namespace NickvisionTagger::UI::Views
{
    /**
     * The MainWindow for the application
     */
    class MainWindow
    {
    public:
    	/**
    	 * Constructs a MainWindow
    	 *
    	 * @param application GtkApplication*
    	 * @param appInfo The AppInfo for the application
    	 */
    	MainWindow(GtkApplication* application, const NickvisionTagger::Controllers::MainWindowController& controller);
    	/**
    	 * Gets the GtkWidget* representing the MainWindow
    	 *
    	 * @returns The GtkWidget* representing the MainWindow 
    	 */
    	GtkWidget* gobj();
    	/**
    	 * Starts the MainWindow
    	 */
    	void start();
    	
    private:
    	NickvisionTagger::Controllers::MainWindowController m_controller;
    	bool m_isSelectionOccuring;
		GtkWidget* m_gobj{ nullptr };
		GtkWidget* m_mainBox{ nullptr };
		GtkWidget* m_headerBar{ nullptr };
		GtkWidget* m_adwTitle{ nullptr };
		GtkWidget* m_btnOpenMusicFolder{ nullptr };
		GtkWidget* m_btnReloadMusicFolder{ nullptr };
		GtkWidget* m_btnMenuHelp{ nullptr };
		GtkWidget* m_sepHeaderEnd{ nullptr };
		GtkWidget* m_btnApply{ nullptr };
		GtkWidget* m_btnMenuTagActions{ nullptr };
		GtkWidget* m_btnMenuWebServices{ nullptr };
		GtkWidget* m_toastOverlay{ nullptr };
		GtkWidget* m_viewStack{ nullptr };
		GtkWidget* m_pageStatusNoFiles{ nullptr };
		GtkWidget* m_pageFlapTagger{ nullptr };
		GtkWidget* m_scrollTaggerContent{ nullptr };
		GtkWidget* m_boxTaggerContent{ nullptr };
		GtkWidget* m_boxSearch{ nullptr };
		GtkWidget* m_txtSearchMusicFiles{ nullptr };
		GtkWidget* m_btnAdvancedSearchInfo{ nullptr };
		GtkWidget* m_listMusicFiles{ nullptr };
		GtkWidget* m_popoverListMusicFiles{ nullptr };
		GtkGesture* m_gestureListMusicFiles{ nullptr };
		GtkWidget* m_sepTagger{ nullptr };
		GtkWidget* m_scrollTaggerFlap{ nullptr };
		GtkWidget* m_boxTaggerFlap{ nullptr };
		GtkWidget* m_adwGrpProperties{ nullptr };
		GtkWidget* m_txtFilename{ nullptr };
		GtkWidget* m_txtTitle{ nullptr };
		GtkWidget* m_txtArtist{ nullptr };
		GtkWidget* m_txtAlbum{ nullptr };
		GtkWidget* m_txtYear{ nullptr };
		GtkWidget* m_txtTrack{ nullptr };
		GtkWidget* m_txtAlbumArtist{ nullptr };
		GtkWidget* m_txtGenre{ nullptr };
		GtkWidget* m_txtComment{ nullptr };
		GtkWidget* m_txtDuration{ nullptr };
		GtkWidget* m_txtChromaprintFingerprint{ nullptr };
		GtkWidget* m_txtFileSize{ nullptr };
		GtkWidget* m_stackAlbumArt{ nullptr };
		GtkWidget* m_btnNoAlbumArt{ nullptr };
		GtkWidget* m_statusNoAlbumArt{ nullptr };
		GtkWidget* m_btnAlbumArt{ nullptr };
		GtkWidget* m_frmAlbumArt{ nullptr };
		GtkWidget* m_imgAlbumArt{ nullptr };
		GtkWidget* m_btnKeepAlbumArt{ nullptr };
		GtkWidget* m_statusKeepAlbumArt{ nullptr };
		GSimpleAction* m_actOpenMusicFolder{ nullptr };
		GSimpleAction* m_actReloadMusicFolder{ nullptr };
		GSimpleAction* m_actApply{ nullptr };
		GSimpleAction* m_actDiscardUnappliedChanges{ nullptr };
		GSimpleAction* m_actDeleteTags{ nullptr };
		GSimpleAction* m_actInsertAlbumArt{ nullptr };
		GSimpleAction* m_actRemoveAlbumArt{ nullptr };
		GSimpleAction* m_actFilenameToTag{ nullptr };
		GSimpleAction* m_actTagToFilename{ nullptr };
		GSimpleAction* m_actDownloadMusicBrainzMetadata{ nullptr };
		GSimpleAction* m_actSubmitToAcoustId{ nullptr };
		GSimpleAction* m_actPreferences{ nullptr };
		GSimpleAction* m_actKeyboardShortcuts{ nullptr };
		GSimpleAction* m_actAbout{ nullptr };
		GSimpleAction* m_actAdvancedSearchInfo{ nullptr };
		GtkDropTarget* m_dropTarget{ nullptr };
		std::vector<GtkWidget*> m_listMusicFilesRows;
		/**
		 * Runs closing functions
		 *
		 * @returns True to stop window from closing, else false
		 */
		bool onCloseRequest();
		/**
    	 * Updates the UI when the music folder is updated
    	 *
    	 * @param showToast True to show a toast with the number of files loaded, else false
    	 */
    	void onMusicFolderUpdated(bool sendToast);
    	/**
    	 * Updates the UI when the saved status of music files is updated
    	 */
    	void onMusicFilesSavedUpdated();
    	/**
    	 * Prompts the user to open a music folder from disk and load it in the app
    	 */
    	void onOpenMusicFolder();
    	/**
    	 * Reloads the music folder and updates the UI
    	 */
    	void onReloadMusicFolder();
    	/**
    	 * Applys the changes to the selected files' tag
    	 */
    	void onApply();
    	/**
    	 * Discards unapplied changes from the selected files
    	 */
    	void onDiscardUnappliedChanges();
    	/**
    	 * Deletes the tags of the selected files
    	 */
    	void onDeleteTags();
    	/**
    	 * Prompts the user to select an image file and applys it as the album art for the selected files
    	 */
    	void onInsertAlbumArt();
    	/**
    	 * Removes the album art from the selected files
    	 */
    	void onRemoveAlbumArt();
    	/**
    	 * Prompts the user to select a format string and performs a filename to tag conversion for the selected files
    	 */
    	void onFilenameToTag();
    	/**
    	 * Prompts the user to select a format string and performs a tag to filename conversion for the selected files
    	 */
    	void onTagToFilename();
    	/**
    	 * Downloads and applys tag metadata from MusicBrainz for the selected files
    	 */
    	void onDownloadMusicBrainzMetadata();
    	/**
    	 * Uploads tag metadata of one selected file to AcoustId
    	 */
    	void onSubmitToAcoustId();
    	/**
    	 * Displays the preferences dialog
    	 */
    	void onPreferences();
    	/**
    	 * Displays the keyboard shortcuts dialog
    	 */
    	void onKeyboardShortcuts();
    	/**
    	 * Displays the about dialog
    	 */
    	void onAbout();
    	/**
    	 * Displays a dialog containing information about the advanced search function
    	 */
    	void onAdvancedSearchInfo();
    	/**
		 * Occurs when the GtkDropTarget is triggered
		 *
		 * @param value The value from the drop
		 * @returns True to accept the drop, else false
		 */
		bool onDrop(const GValue* value);
    	/**
    	 * Occurs when txtSearchMusicFile's text is changed
    	 */
    	void onTxtSearchMusicFilesChanged();
    	/**
    	 * Occurs when listMusicFile's selection is changed
    	 */
		void onListMusicFilesSelectionChanged();
		/**
    	 * Occurs when listMusicFile is right clicked
    	 */
		void onListMusicFilesRightClicked(int n_press, double x, double y);
		/**
		 * Occurs when tag property text entry is changed
		 */
		void onTxtTagPropertyChanged();
    };
}