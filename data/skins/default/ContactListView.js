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
 *
 * Show contacts under the group.
 **/
function ContactListView_expand()
{
	alert("ContactListView_expand");
	
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
	alert("ContactListView_groupNode");
	
}

/**
 * ContactListView_contactNode:
 *
 * Contact node entity.
 **/
function ContactListView_contactNode()
{
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
}
/**
 * ContactListView_addContact:
 * @gid:                Group Id
 * @type:               Type of the contact (person/room)
 * @avatar:             The avatar to show in the screen
 * @name_str:           The name string to show in the screen
 * @impresa_str:        The impresa string to show in the screen
 * @add_to_top:         Add the new message to the top of the list
 *
 * Add a individual contact under a group (target with group id).
 **/
function ContactListView_addContact(gid, type, avatar, name_str, impresa_str,
                                    add_to_top)
{
	if (add_to_top){
	
	} else {
	
	}
	/* Find target group based on id */
}