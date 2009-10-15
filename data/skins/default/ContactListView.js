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
 * ContactListView_groupClicked:
 * @gid:                Group Id
 *
 * Show contacts under the group.
 **/
function ContactListView_groupClicked(gid)
{
    //alert("ContactListView_expand");
    // var c = document.getElementById("Contact");
    // c.removeAttribute('style');
    //TODO: display all the child nodes (contacts) under the group
}

/**
 * ContactListView_contactClicked:
 *
 * Show contact detail information.
 **/
function ContactListView_contactClicked()
{
    alert("ContactListView_contactClicked");
}

/**
 * ContactListView_contactDoubleClicked:
 *
 * Start a chat with selected contact.
 **/
function ContactListView_contactDoubleClicked()
{
    alert("ContactListView_contactDoubleClicked");
}

/**
 * ContactListView_flush:
 *
 * Flush buffer for renderring.
 **/
function ContactListView_flush()
{
    alert("ContactListView_flush");
	
}
/**
 * ContactListView_groupNode:
 * @gid:                Group Id of the nodes
 * @expander:           The expander image of the node
 * @group_name:         The group name of the node
 * @number:             online contact number vs. total number
 *
 * Group node entity.
 **/
function ContactListView_groupNode(item)
{
    var new_group;
    var expander;
    var group_name;
    var number;

    alert("ContactListView_groupNode");
    if(item.type != 0)
    {
        alert("");
        return;
    }
    if(item.group == false)
        return;
    var type = "Group";
    new_group = markupTemplateGroup.cloneNode(true);
    new_group.id = type + item.gid;
    new_group.onclick = ContactListView_groupExpand;

    /* Retrieve the elements to update the node */
    var node_tags = new_group.getElementsByTagName('*');
    for (var i = 0; i < node_tags.length; i++) {
        if (node_tags[i].hasAttribute('id')) {
            var id = node_tags[i].getAttribute('id');
            if (id == (type + "Expander"))
                expander = node_tags[i];
            if (id == (type + "Name"))
                group_name = node_tags[i];
            if (id == (type + "OnlineNumber"))
                number = node_tags[i];
        }
    }
}

/**
 * ContactListView_contactNode:
 * @item:            Contact information
 *
 * Contact node entity.
 **/
function ContactListView_contactNode(item)
{
    var new_contact;
    var avatar_img;
    var contact_name;
    var contact_impresa;
    var type = "Contact";

    alert("ContactListView_contactNode");
    if(item.type != 0)
    {
        alert("");
        return;
    }
    if(item.contact == false)
        return;

    new_contact = markupTemplateContact.cloneNode(true);
    new_contact.id = type + item.gid;
    new_contact.onclick = ContactListView_contactClicked;
    new_contact.ondblclick = ContactListView_contactDoubleClicked;

    /* Retrieve the elements to update the node */
    var node_tags = new_contact.getElementsByTagName('*');
    for (var i = 0; i < node_tags.length; i++) {
        if (node_tags[i].hasAttribute('id')) {
            var id = node_tags[i].getAttribute('id');
            if (id == (type + "Avatar"))
                avatar_img = node_tags[i];
            if (id == (type + "Name"))
                contact_name = node_tags[i];
            if (id == (type + "Impresa"))
                contact_impresa = node_tags[i];
        }
    }

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
