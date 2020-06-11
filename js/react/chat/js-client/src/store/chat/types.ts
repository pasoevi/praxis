export interface Message {
    id: string;
    author: string;
    text: string;
    timestamp: number;
}

export interface ChatState {
  messages: Message[];
}

// Describing the different ACTION NAMES available
export const SEND_MESSAGE = "SEND_MESSAGE";
export const DELETE_MESSAGE = "DELETE_MESSAGE";

interface SendMessageAction {
  type: typeof SEND_MESSAGE;
  payload: string;
}

interface DeleteMessageAction {
  type: typeof DELETE_MESSAGE;
  meta: {
    timestamp: number;
  };
}

export type ChatActionTypes = SendMessageAction | DeleteMessageAction;
