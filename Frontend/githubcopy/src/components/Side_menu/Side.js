import React from "react";
import side from "./Side.module.css";
import SVG from "../SimpleComponents/SVG";
import ProfileIcon from "../SimpleComponents/ProfileIcon/ProfileIcon";
import json from "../../static/Images/Images";
const Side = () => {
  return (
    <aside className={side.sidecontainer}>
      <div className={side.sidebar}>
        <h2 className={side.up}>
          Recent Repositories
          <a className={side.newrepo} href="/#">
            <SVG type={"Repository"} name="joaq" />
            New
          </a>
        </h2>

        <input
          type="text"
          placeholder="Find a repository..."
          autoCapitalize="off"
          aria-controls="jump-to-results"
          aria-label="Find a repository..."
          style={{ width: "75%", marginTop: "0px" }}
        />
      </div>
      <ul>
        {[
          ["feijoes/Yu-Gi-Oh", "https://github.com/feijoes/Yu-Gi-Oh"],
          ["moura-code/bookshare", "https://github.com/feijoes/Yu-Gi-Oh"],
          ["moura-code/minesweeper", "https://github.com/feijoes/Yu-Gi-Oh"],
        ].map((text) => {
          return (
            <li key={text[0]}>
              <ProfileIcon image={json.ProfileIconfeijoes.image} />
              <a className={side.list} href={text[1]}>
                {text[0]}
              </a>
            </li>
          );
        })}
      </ul>
      <hr className={side.line} />
      <h5 className={side.text}>Recent activity</h5>
      <p className={side.text2}>
        When you take actions across GitHub, we’ll provide links to that
        activity here.
      </p>
    </aside>
  );
};

export default Side;
