import { v4 } from "node-uuid";
import { SEND_MESSAGE, DELETE_MESSAGE } from "./types";
import { CURRENT_USER_ID } from "../system/types";

export function sendMessage(text: string) {
  return {
      type: SEND_MESSAGE,
      payload: { text, id: v4(), timestamp: Date.now(), sender: {id: CURRENT_USER_ID, displayName: "You"}},
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
