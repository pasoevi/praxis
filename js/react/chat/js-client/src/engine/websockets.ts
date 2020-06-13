import io from "socket.io-client";
import { temporaryAny } from "../types";
import { RECEIVE_MESSAGE } from "../store/chat/types";
import { Message } from "../store/chat/types";
import { CURRENT_USER_ID } from "../store/system/types";

const uri = "http://localhost:80";

const messageTypes = {
    CHAT_MESSAGE: true,
};

const socket = io();
export const init = (store: temporaryAny) => {
    socket.on(RECEIVE_MESSAGE, (payload: Message) => {
        if (payload.sender.id !== CURRENT_USER_ID) {
            return store.dispatch({ RECEIVE_MESSAGE, payload });
        }
    });
};
// Object.keys(messageTypes).forEach((type) =>
// );
//};

export const emit = (type: string, payload: Message) =>
    socket.emit(type, payload);
