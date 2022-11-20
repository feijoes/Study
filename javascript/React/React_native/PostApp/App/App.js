import { StatusBar } from "expo-status-bar";
import React, { useState } from "react";
import { StyleSheet, View } from "react-native";
import { AuthScreen,Home } from "./screens/";
import AsyncStorage from "@react-native-async-storage/async-storage";


export default function App() {
  React.useEffect(() => {
    // Fetch the token from storage then navigate to our appropriate place
    
    const get = async () => {
      let userToken;

      try {
        userToken = await AsyncStorage.getItem("Token");

        if (userToken != null) {
     
          setIsUserLogin(true);
        } else {
          
          setIsUserLogin(false);
        }
      } catch (e) {
        console.log(e);
      }
    };

    get();
  }, []);

  [userIsLogin, setIsUserLogin] = useState(false);
  const [view, setView]= useState(null)
  React.useEffect(() => {
    // Fetch the token from storage then navigate to our appropriate place
    setView(userIsLogin ? <Home setIsUserLogin={setIsUserLogin} />: <AuthScreen setIsUserLogin={setIsUserLogin}/>);
  }, [userIsLogin]);

  return (
    <View style={styles.container}>
      {view}
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
