import React from "react";
import style from "./Aside.module.css";
import SVG from "../SimpleComponents/SVG";
const Aside = () => {
  return (
    <aside className={style.main}>
      <div className={style.log}>
        <h3> Latest changes</h3>
        <ul className={style.lis}>
          {[
            [
              "moura-code Acount",
              "https://github.com/moura-code",
              "3 days ago",
            ],
            ["Feijoes Acount ", "https://github.com/feijoes", "7 days ago"],
          ].map((text) => {
            return (
              <li className={style.item}>
                <div className={style.svgdiv}>
                  <SVG type="ball" stylesvg={style.svg} />
                </div>
                <div className={style.text}>
                  {text[2]}
                  <h1 className={style.h}>
                    <a className={style.link} href={text[1]}>
                      {text[0]}
                    </a>
                  </h1>
                </div>
              </li>
            );
          })}
        </ul>
      </div>
      <div className={style.repositories}>
        <p>Explore repositories</p>
        <ul className={style.lis}>
        {[
            [
              "study/local-startegy",
              "https://github.com/moura-code/study/local-startegy",
              "description rtbrtbertghrtegtrergwergwergwerg wergwre g wer g",
              'yellow',
              'javascript',
              '33'
            ],
            [
              "Study/javascript",
              "https://github.com/feijoes/Study/tree/master/javascript/Node_API",
              "description",
              'yellow',
              'javascript',
              '17'
            ],
            
          ].map((text) => {
            return (
              <li>
            <h1 className={style.h}>
              <a className={style.link} href={text[1]}>
               {text[0]}
              </a>
            </h1>
            <p className={style.mini}>{text[2]}</p>

            <span
              style={{
                display: "flex",
                alignItems: "center",
                marginTop: "10px",
              }}
            >
              <span
                style={{ backgroundColor: text[3] }}
                className={style.circul}
              >
                {" "}
              </span>
              <p className={style.mini}>{text[4]}</p>
              <SVG type={"star"} /> <p className={style.mini} style={{'marginLeft':'6px'}}>{text[5]}</p>
            </span>
            <hr className={style.line}/>
          </li>
            );
          })}
          
        </ul>
      </div>
    </aside>
  );
};

export default Aside;
