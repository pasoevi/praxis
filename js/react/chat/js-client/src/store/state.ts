import { Message } from "./chat/types";
import { temporaryAny } from "../types";

// Actions
const LOAD = "chat/messages/LOAD";
const SEND = "chat/messages/SEND";
const RECEIVE = "chat/messages/RECEIVE";

interface SettingsState {
    displayUnreadCount: false;
    darkMode: false;
}

interface RootState {
    messages: Array<Message>;
    settings: SettingsState;
}

export interface Action {
    type: string;
}

const defaultAction: Action = {
    type: "default",
};


// Action Creators
export function loadMessages() {
    return { type: LOAD };
}


// side effects, only as applicable
// e.g. thunks, epics, etc
export function receiveMessages() {
    return (dispatch: temporaryAny) =>
        fetch("/messages")
            .then((res) => res.json())
            .then((message: Message) => dispatch(loadMessages()));
}
