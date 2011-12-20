INSTRUCTIONS:
1. Install and enable the module.
2. To sync zotero tags, you need to specify the tags vocab you want to use in the zotero processor
settings here: <yoursite>/admin/build/feeds/edit/zotero_feed/settings/FeedsZoteroProcessor. 
Don't forget to apply the tags vocab to the biblio node first, or you wont be able to select it
in the processor settings form.
3. Create a new zotero_feed node. <yoursite>/node/add/zotero-feed
4. Expand the "feed" fieldset if it's collapsed
5. Enter your user or group id. (Instructions are on the edit form).
6. Save the feed and it will import the library.

TODO:
sync updates to previously imported items
implement and test apikey for non-public libraries
add un-mapped fields to allow mapping to CCK fields in the Feeds UI.
