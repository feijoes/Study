import React, { useState } from "react";
import {
  View,
  Text,
  StyleSheet,
  TouchableOpacity,
  TextInput,
  Platform,
  RefreshControl,
} from "react-native";
import axios from "axios";
import { useKeyboard } from "../components";
import AsyncStorage from "@react-native-async-storage/async-storage";

const API_URL =
  Platform.OS === "ios" ? "http://localhost:5000/" : "http://10.0.2.2:5000/";

export const AuthScreen = ({setIsUserLogin}) => {
  const [inputs, setInputs] = useState({});
  const [isLogin, setIsLogin] = useState(true);
  const [message, setMessage] = useState("");
  const [isError, setIsError] = useState(false);
  const [isRefresh, setRefresh] = useState(false);
  const isKeyboardOpen = useKeyboard();

  const SendData = () => {
    if (!isLogin)
      if (!inputs.name) {
        setIsError(true);
        setMessage("Complete all forms");
        return;
      }
    if (!(inputs.email && inputs.password)) {
      setIsError(true);
      setMessage("Complete all forms");
      return;
    }
    if (inputs.confirmPassword != inputs.password) {
      setIsError(true);
      setMessage("Passwords Must Be The Same");
      return;
    } else {
      const body = !isLogin
        ? {
            username: inputs.name,
            email: inputs.email,
            password: inputs.password,
          }
        : {
            email: inputs.email,
            password: inputs.password,
          };

      axios
        .post(
          `${API_URL}routes/users/${isLogin ? "login" : "register"}`,
          body,
          {
            headers: {
              "Content-Type": "application/json",
            },
            withCredentials: true,
          }
        )
        .then((request) => {
          if (request.data.success) {
            setIsError(false);
            setMessage("You Are Login");
          }

          AsyncStorage.setItem("Token", request.data.token);
          setIsUserLogin(true)
        })
        .catch((error) => {
          console.log(error);
          setIsError(true);
          setMessage(error.response.data.msg);
        });

      setInputs({});
    }
  };

  const onChangeHandler = (value, name) => {
    setRefresh(true)
    setInputs((values) => ({ ...values, [name]: value }));
  };

  const changelogin = () => {
    setIsLogin(!isLogin);
    setMessage("");
  };

  return (
    <View style={styles.card}>
      <RefreshControl refreshing={isRefresh} onRefresh={()=>console.log(1)} />
      <Text style={styles.heading}>{isLogin ? "Login" : "Signup"}</Text>
      <View style={styles.form}>
        <View style={styles.inputs}>
          <TextInput
            style={styles.input}
            placeholder="Email"
            autoCapitalize="none"
            name="email"
            value={inputs.email || ""}
            onChangeText={(e) => onChangeHandler(e, "email")}
          ></TextInput>
          {!isLogin && (
            <TextInput
              style={styles.input}
              placeholder="Name"
              name="name"
              value={inputs.name || ""}
              onChangeText={(e) => onChangeHandler(e, "name")}
            ></TextInput>
          )}
          <TextInput
            secureTextEntry={true}
            style={styles.input}
            placeholder="Password"
            name="password"
            value={inputs.password || ""}
            onChangeText={(e) => onChangeHandler(e, "password")}
          ></TextInput>
          <TextInput
            secureTextEntry={true}
            style={styles.input}
            placeholder="Confirm Password"
            value={inputs.confirmPassword || ""}
            name="confirmPassword"
            onChangeText={(e) => onChangeHandler(e, "confirmPassword")}
          ></TextInput>
          {message && (
            <Text
              style={[styles.message, { color: isError ? "red" : "green" }]}
            >
              {message}
            </Text>
          )}

          <TouchableOpacity
            style={[styles.button, { marginTop: isKeyboardOpen ? "7%" : 50 }]}
            onPress={SendData}
          >
            <Text style={styles.buttonText}>Done</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.buttonAlt} onPress={changelogin}>
            <Text style={styles.buttonAltText}>
              {isLogin ? "Sign Up" : "Log In"}
            </Text>
          </TouchableOpacity>
        </View>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  image: {
    flex: 1,
    width: "100%",
    alignItems: "center",
  },
  card: {
    flex: 1,
    backgroundColor: "rgba(255, 255, 255, 0.4)",
    width: "80%",
    marginTop: "37%",
    borderRadius: 20,
    maxHeight: 380,
    paddingBottom: "30%",
  },
  heading: {
    fontSize: 30,
    fontWeight: "bold",
    marginLeft: "10%",
    marginTop: "5%",
    marginBottom: "45%",
    color: "black",
  },
  form: {
    flex: 1,
    justifyContent: "space-between",
    paddingBottom: "10%",
  },
  inputs: {
    width: "100%",
    flex: 1,
    alignItems: "center",
    justifyContent: "center",
  },
  input: {
    width: "80%",
    borderBottomWidth: 1,
    borderBottomColor: "black",
    paddingTop: 10,
    fontSize: 16,
    minHeight: 40,
  },
  button: {
    width: "80%",
    backgroundColor: "black",
    height: 40,
    borderRadius: 50,
    justifyContent: "center",
    alignItems: "center",
    marginVertical: 5,
  },
  buttonText: {
    color: "white",
    fontSize: 16,
    fontWeight: "400",
  },
  buttonAlt: {
    width: "80%",
    borderWidth: 1,
    height: 40,
    borderRadius: 50,
    borderColor: "black",
    justifyContent: "center",
    alignItems: "center",
    marginVertical: 5,
  },
  buttonAltText: {
    color: "black",
    fontSize: 16,
    fontWeight: "400",
  },
  message: {
    fontSize: 16,
    marginVertical: "1%",
    marginBottom: -10,
    height: 30,
    width: "80%",
    paddingTop: 10,
  },
});
