import {
    configureStore,
    getDefaultMiddleware,
    ThunkAction,
    Action,
} from "@reduxjs/toolkit";
import { loggerMiddleware } from "./middleware/loggerMiddleware";

import { combineReducers } from "@reduxjs/toolkit";

import { systemReducer } from "./system/reducers";
import { chatReducer } from "./chat/reducers";

export const rootReducer = combineReducers({
    system: systemReducer,
    chat: chatReducer,
});


export type AppState = ReturnType<typeof store.getState>;

export type AppThunk<ReturnType = void> = ThunkAction<
    ReturnType,
    AppState,
    unknown,
    Action<string>
>;

export const store = configureStore({
    reducer: rootReducer,
    middleware: [loggerMiddleware, ...getDefaultMiddleware()],
});
