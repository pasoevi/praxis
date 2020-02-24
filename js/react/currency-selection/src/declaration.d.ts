// declaration.d.ts
/* declare module '*.css' {
    const content: {[className: string]: string};
    export default content;
}
 */
declare module '*.css' {
    interface IClassNames {
      [className: string]: string
    }
    const classNames: IClassNames;
    export = classNames;
}