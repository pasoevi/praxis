import { Action, MiddlewareAPI, Dispatch } from "@reduxjs/toolkit";
import { temporaryAny } from "../../types";

export const loggerMiddleware: temporaryAny = (
    api: MiddlewareAPI<temporaryAny>,
) => (next: Dispatch<temporaryAny>) => <A extends Action>(action: A) => {
    console.log("dispatching", action);
    console.log("next state", api.getState());
    return next(action);
};

const socketMiddleware = () => {
    let socket = null;

    const onOpen = (store) => (event) => {
        console.log("websocket open", event.target.url);
        store.dispatch(actions.wsConnected(event.target.url));
    };

    const onClose = (store) => () => {
        store.dispatch(actions.wsDisconnected());
    };

    const onMessage = (store) => (event) => {
        const payload = JSON.parse(event.data);
        console.log("receiving server message");

        switch (payload.type) {
            case "update_game_players":
                store.dispatch(
                    updateGame(payload.game, payload.current_player),
                );
                break;
            default:
                break;
        }
    };

    // the middleware part of this function
    return (api: MiddlewareAPI<temporaryAny>) => (next: Dispatch<temporaryAny>) => <A extends Action>(action: A) =>  {
        switch (action.type) {
            case "WS_CONNECT":
                if (socket !== null) {
                    socket.close();
                }

                // connect to the remote host
                socket = new WebSocket(action.host);

                // websocket handlers
                socket.onmessage = onMessage(api);
                socket.onclose = onClose(api);
                socket.onopen = onOpen(api);

                break;
            case "WS_DISCONNECT":
                if (socket !== null) {
                    socket.close();
                }
                socket = null;
                console.log("websocket closed");
                break;
            case "NEW_MESSAGE":
                console.log("sending a message", action.msg);
                socket.send(
                    JSON.stringify({
                        command: "NEW_MESSAGE",
                        message: action.msg,
                    }),
                );
                break;
            default:
                console.log("the next action:", action);
                return next(action);
        }
    };
};

export const websocketMiddleware = socketMiddleware();