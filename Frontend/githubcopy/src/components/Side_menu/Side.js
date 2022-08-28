import React from "react";
import side from "./Side.module.css";

const Side = () => {
  return (
    <aside className={side.sidecontainer}>
      <div className={side.sidebar}>
        <h2 className={side.up}>
          Recent Repositories
          <a className={side.newrepo} href='/#'>
             New 
          </a>
        </h2>
      </div>
    </aside>
  );
};

export default Side;
