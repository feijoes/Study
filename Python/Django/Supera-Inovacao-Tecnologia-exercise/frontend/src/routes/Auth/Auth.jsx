import { useRef, useState, useEffect, useContext } from "react";
import "./Auth.css";
import axios from "axios";
import { Link } from "react-router-dom";
import { AuthContext } from "../../context";

const Auth = () => {
  const userRef = useRef();
  const errRef = useRef();
  const [user, setUser] = useState("");
  const [pwd, setPwd] = useState("");
  const [email, setEmail] = useState("");
  const [errMsg, setErrMsg] = useState("");
  const [Type, setType] = useState(false);
  const { cookies, setAuth, LOGIN_URL, isLogin } = useContext(AuthContext);
  const [success, setSuccess] = useState(false)

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      const response = Type
        ? await axios.post(
            LOGIN_URL + "register/",
            JSON.stringify({ username: user, email: email, password: pwd }),
            {
              headers: { "Content-Type": "application/json" },
            }
          )
        : await axios.post(
            LOGIN_URL + "login/",
            JSON.stringify({ username: user, password: pwd }),
            {
              headers: { "Content-Type": "application/json" },
            }
          );
      const accessToken = response?.data?.token;
      setAuth({ user, pwd, accessToken });
      cookies.set("accessToken", accessToken, { path: "/" });
      setSuccess(true)
      setUser("");
      setPwd("");
      setEmail("");
    } catch (err) {
      console.log(err);
      if (!err?.response) {
        setErrMsg("No Server Response");
      } else if (err.response?.status === 400) {
        setErrMsg("Missing Username or Password");
      } else if (err.response?.status === 401) {
        setErrMsg("Unauthorized");
      } else {
        setErrMsg("Login Failed");
      }
      errRef.current.focus();
    }
  };
  useEffect(() => {
    userRef.current?.focus();
  }, []);
  useEffect(() => {
    setErrMsg("");
  }, [user, pwd]);

  return (
    <div
      style={{
        display: "flex",
        alignItems: "center",
        justifyContent: "center",
      }}
    >
      {isLogin ||success  ? (
        <section>
          <h1>You are logged in!</h1>
          <br />
          <Link to="/">Go to Home page</Link>

        </section>
      ) : (
        <section>
          <p
            ref={errRef}
            className={errMsg ? "errmsg" : "offscreen"}
            aria-live="assertive"
          >
            {errMsg}
          </p>
          <h1>{Type ? "Sign Up" : "Sign In"}</h1>
          <form onSubmit={handleSubmit}>
            <label htmlFor="username">Username:</label>
            <input
              type="text"
              id="username"
              ref={userRef}
              autoComplete="off"
              onChange={(e) => setUser(e.target.value)}
              value={user}
              required
            />
            {Type && (
              <>
                <label htmlFor="email">Email:</label>
                <input
                  type="text"
                  id="email"
                  onChange={(e) => setEmail(e.target.value)}
                  value={email}
                  required
                />
              </>
            )}
            <label htmlFor="password">Password:</label>
            <input
              type="password"
              id="password"
              onChange={(e) => setPwd(e.target.value)}
              value={pwd}
              required
            />
            <button>Sign In</button>
          </form>
          <p>
            {Type ? "Already have a account?" : "Dont have a account?"}
            <br />
            <span className="line">
              <a href="#" onClick={(e) => setType((r) => !r)}>
                {Type ? "Sign in" : "Sign Up"}
              </a>
            </span>
          </p>
        </section>
      )}
    </div>
  );
  return;
};

export default Auth;
