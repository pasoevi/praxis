import { v4 } from "node-uuid";
import { SEND_MESSAGE, DELETE_MESSAGE, RECEIVE_MESSAGE } from "./types";
import { CURRENT_USER_ID } from "../system/types";
import { emit } from "../../engine/websockets";

export function sendMessage(text: string) {
    const newMessage = {
        text,
        id: v4(),
        timestamp: Date.now(),
        sender: { id: CURRENT_USER_ID, displayName: "You" },
    };
    emit(SEND_MESSAGE, newMessage);
    return {
        type: SEND_MESSAGE,
        payload: newMessage,
    };
}

// Action Creators
export function messageReceived() {
    return { type: RECEIVE_MESSAGE, payload: Message };
}

// side effects, only as applicable
// e.g. thunks, epics, etc
export function receiveMessages() {
    return (dispatch: temporaryAny) =>
        fetch("/messages")
            .then((res) => res.json())
            .then((message: Message) => dispatch(messageReceived()));
}

export function deleteMessage(timestamp: number) {
    return {
        type: DELETE_MESSAGE,
        meta: {
            timestamp,
        },
    };
}
