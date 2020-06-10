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
        timestamp: Date.now(),
        text: "Do you want to bang tonight?",
    },
    {
        id: "2",
        author: "Sergo Pasoevi",
        timestamp: Date.now(),
        text: "Do you want to bang tonight?",
    },
    {
        id: "3",
        author: "You",
        timestamp: Date.now(),
        text: "Do you want to bang tonight?",
    },
];

const initialState: ChatState = {
    messages: mockMessages,
};

function uuidv4() {
    let dt = new Date().getTime();
    const uuid = "xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx".replace(
        /[xy]/g,
        function (c) {
            const r = (dt + Math.random() * 16) % 16 | 0;
            dt = Math.floor(dt / 16);
            return (c === "x" ? r : (r & 0x3) | 0x8).toString(16);
        },
    );
    return uuid;
}

export function chatReducer(
    state = initialState,
    action: ChatActionTypes,
): ChatState {
    switch (action.type) {
    case SEND_MESSAGE: {
        const newMessage: Message = {
            id: uuidv4(),
            author: "Sergo Pasoevi",
            text: action.payload,
            timestamp: Date.now(),
        };
        return {
            messages: [...state.messages, newMessage],
        };
    }
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
