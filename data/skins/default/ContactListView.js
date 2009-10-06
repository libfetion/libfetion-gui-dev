/**
 * @file ContactListView.js
 *
 * Javascript for contact list view rendering widget's ring buffer.
 */

var test = true;

var markupTemplateGroup;
var markupTemplateContact;

function ContactListView_init()
{

}

/**
 * ContactListView_expand:
 * @gid:                Group Id
 *
 * Show contacts under the group.
 **/
function ContactListView_expand(gid)
{
    //alert("ContactListView_expand");
    // var c = document.getElementById("Contact");
    // c.removeAttribute('style');
    //TODO: display all the child nodes (contacts) under the group
}

/**
 * ContactListView_chat:
 *
 * Start chat .
 **/
function ContactListView_chat()
{
    alert("ContactListView_chat");
}

/**
 * ContactListView_contactClicked:
 *
 * Show contact info details.
 **/
function ContactListView_contactClicked()
{
    alert("ContactListView_contactClicked");
}

/**
 * ContactListView_expand:
 *
 * Flush buffer for renderring.
 **/
function ContactListView_flushBuffer()
{
    alert("ContactListView_expand");
	
}
/**
 * ContactListView_groupNode:
 *
 * Group node entity.
 **/
function ContactListView_groupNode()
{
    var new_group;
    var expander;
    var group_name;
    var number;

    alert("ContactListView_groupNode");
}

/**
 * ContactListView_contactNode:
 *
 * Contact node entity.
 **/
function ContactListView_contactNode()
{
    var new_contact;
    var avatar_img;
    var contact_name;
    var contact_impresa;

    alert("ContactListView_contactNode");
}
/**
 * ContactListView_addGroup:
 * @gid:                Group Id
 * @group_name_str:     The name string of group
 * @number_str:         The time string to show in the screen
 *
 * This group differs from fetion Qun concept. Qun is 'Room' in our application.
 * Each group will have its own group id for distinct different contact list 
 * under that group.
 **/
function ContactListView_addGroup(gid, group_name_str, number_str)
{
    alert("ContactListView_addGroup");
}
/**
 * ContactListView_addContact:
 * @gid:                Group Id
 * @type:               Type of the contact (person/room)
 * @avatar:             The avatar to show in the screen
 * @name_str:           The name string to show in the screen
 * @impresa_str:        The impresa string to show in the screen
 *
 * Add a individual contact under a group (target with group id).
 **/
function ContactListView_addContact(gid, type, avatar, name_str, impresa_str)
{
    alert("ContactListView_addContact");

    /* Find target group based on id */
}
