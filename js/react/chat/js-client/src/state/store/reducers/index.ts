import { combineReducers } from "@reduxjs/toolkit";

import { systemReducer } from "../system/reducers";
import { chatReducer } from "../chat/reducers";

export const rootReducer = combineReducers({
    system: systemReducer,
    chat: chatReducer,
});
