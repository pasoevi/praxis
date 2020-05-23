import {
    ChatState,
    SEND_MESSAGE,
    DELETE_MESSAGE,
    ChatActionTypes,
    Message,
} from "./types";

const mockMessages: Message[] = [
    {
        id: "1",
        author: "Sergo Pasoevi",
        dateSent: new Date(),
        timestamp: Date.now(),
        text: "Do you want to bang tonight?",
    },
    {
        id: "2",
        author: "Sergo Pasoevi",
        dateSent: new Date(),
        timestamp: Date.now(),
        text: "Do you want to bang tonight?",
    },
    {
        id: "3",
        author: "You",
        dateSent: new Date(),
        timestamp: Date.now(),
        text: "Do you want to bang tonight?",
    },
];

const initialState: ChatState = {
    messages: mockMessages,
};

export function chatReducer(
    state = initialState,
    action: ChatActionTypes,
): ChatState {
    switch (action.type) {
        case SEND_MESSAGE:
            return {
                messages: [...state.messages, action.payload],
            };
        case DELETE_MESSAGE:
            return {
                messages: state.messages.filter(
                    (message) => message.timestamp !== action.meta.timestamp,
                ),
            };
        default:
            return state;
    }
}
