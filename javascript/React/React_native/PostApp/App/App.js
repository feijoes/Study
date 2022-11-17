import { StatusBar } from "expo-status-bar";
import React, { useState } from "react";
import { StyleSheet, View, Text } from "react-native";
import { AuthScreen } from "./screens/";
import AsyncStorage from "@react-native-async-storage/async-storage";


export default function App() {
 
  React.useEffect(() => {
    // Fetch the token from storage then navigate to our appropriate place
    const get = async () => {
      let userToken;

      try {
        userToken = await AsyncStorage.getItem("Token");
        console.log(userToken)
        if (userToken) setIsUserLogin(true);
      } catch (e) {
        console.log(e);
      }
    };

    get();
  }, []);
  [userIsLogin, setIsUserLogin] = useState(false);
  return (
    <View style={styles.container}>
      {userIsLogin ? <Text>YOU ARE LOGIn</Text> : <AuthScreen />}
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
  },
});
