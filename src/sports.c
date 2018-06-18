/* This is a managed file. Do not delete this comment. */

#include <mount_app/mount_app.h>

int16_t mount_app_sports_construct(
    mount_app_sports this)
{
    corto_info("mount '%s' created", corto_idof(this));

    /*
    mount_app_team *t = mount_app_teamList__append_alloc(this->mock_teams);
    corto_stringList__append(t->members, "Ricardo");
    corto_stringList__append(t->members, "Sander");
    */

    /* Append a new result element to the mock_teams list */
    corto_result *r = corto_resultList__append_alloc(this->mock_teams);
    corto_set_str(&r->id, "Team Corto");
    corto_set_str(&r->parent, ".");
    corto_set_str(&r->type, "mount_app/team");
    r->value = (uintptr_t)strdup("{\"members\":[\"Ricardo\",\"Sander\"]}");

    corto_mount_setContentType(this, "text/json");

    /* Call constructur of base class (corto.vstore.mount) */
    return corto_super_construct(this);
}


void mount_app_sports_on_notify(
    mount_app_sports this,
    corto_subscriber_event *event)
{
    corto_info("event received! for object '%s'",
        event->data.id);
}


anonymous_mount_app_0 mount_app_sports_on_query(
    mount_app_sports this,
    corto_query *query)
{
    corto_info("query received! select = '%s' from = '%s'",
        query->select, query->from);

    corto_iter it = corto_ll_iter(this->mock_teams);
    while (corto_iter_hasNext(&it)) {
        corto_result *r = corto_iter_next(&it);
        corto_mount_return(this, r);
    }

    return CORTO_ITER_EMPTY;
}
