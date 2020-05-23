import { Message } from "./store/chat/types";
import { Dispatch } from "react";
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

// Reducer
export default function reducer(state = {}, action = defaultAction) {
    switch (action.type) {
        default:
            return state;
    }
}

// Action Creators
export function loadMessages() {
    return { type: LOAD };
}

export function sendMessage(message: Message) {
    return { type: SEND, widget: message };
}

export function updateWidget(message: Message) {
    return { type: RECEIVE, widget: message };
}

// side effects, only as applicable
// e.g. thunks, epics, etc
export function receiveMessages() {
    return (dispatch: temporaryAny) =>
        fetch("/messages")
            .then((res) => res.json())
            .then((message: Message) => dispatch(updateWidget(message)));
}
