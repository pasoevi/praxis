import * as React from "react";

export class Task extends React.Component {
    render() {
        return <div>{this.props.title}</div>;
    }
}