import { SEND_MESSAGE, DELETE_MESSAGE } from "./types";

export function sendMessage(text: string) {
  return {
    type: SEND_MESSAGE,
    payload: text
  };
}

export function deleteMessage(timestamp: number) {
  return {
    type: DELETE_MESSAGE,
    meta: {
      timestamp
    }
  };
}
