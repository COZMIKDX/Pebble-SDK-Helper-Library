#include <pebble.h>
const int inbox_size = 128;
const int outbox_size = 128;

void inbox_received() {

}

void inbox_dropped() {
    
}

void outbox_failed() {

}

void outbox_sent() {

}

void register_app_message_boxes() {
    app_message_register_inbox_received(inbox_received);
    app_message_register_inbox_dropped(inbox_dropped);
    app_message_register_outbox_failed(outbox_failed);
    app_message_register_outbox_sent(outbox_sent);
}

void start_app_messages(){
    register_app_message_boxes();
    app_message_open(inbox_size, outbox_size);
}