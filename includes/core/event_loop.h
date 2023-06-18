#pragma once


namespace core {
    enum class EventType {
        kNothing,
        kRecievedMessage,
        kKeyPressed,
    };


    struct EventKeyPressed {
        int key_code;
    };


    struct EventRecievedMessage {};


    struct Event {
        union Content {
            EventKeyPressed key_pressed;
            EventRecievedMessage recieved_message;
        };

        EventType type;
    };
}
