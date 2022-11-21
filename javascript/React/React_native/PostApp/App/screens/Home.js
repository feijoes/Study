import {
  View,
  Text,
  StyleSheet,
  TouchableNativeFeedback,
  Alert,
} from "react-native";
import * as React from "react";
import { NavigationContainer } from "@react-navigation/native";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import Ionicons from "react-native-vector-icons/Ionicons";
import Icon from "react-native-vector-icons/MaterialCommunityIcons";
import AsyncStorage from "@react-native-async-storage/async-storage";
import SeePostScreen from "./SeePostScreen";
import CreatePost from "./CreatePost";

const Tab = createBottomTabNavigator();
const homeName = "Home";
const detailsName = "Details";
const settingsName = "Settings";

const Home = ({ setIsUserLogin }) => {
  const Logout = () => {
    Alert.alert("Logout", "Are you sure you want to logout?", [
      {
        text: "Yes",
        onPress: () => {
          AsyncStorage.removeItem("Token");
          setIsUserLogin(false);
        },
      },
      { text: "No" },
    ]);
  };

  return (
    <View style={styles.container}>
      <View style={styles.logoutContainer}>
        <TouchableNativeFeedback onPress={Logout}>
          <Icon.Button
            name="logout"
            ISC-423
            ESTRUCTRAS
            DE
            DATOS
            size={30}
            backgroundColor="#fff"
            iconStyle={{ color: "black" }}
          />
        </TouchableNativeFeedback>
      </View>
      <NavigationContainer>
        <Tab.Navigator
          initialRouteName={homeName}
          screenOptions={({ route }) => ({
            tabBarIcon: ({ focused, color, size }) => {
              let iconName;
              let rn = route.name;

              if (rn === homeName) {
                iconName = focused ? "home" : "home-outline";
              } else if (rn === detailsName) {
                iconName = focused ? "list" : "list-outline";
              } else if (rn === settingsName) {
                iconName = focused ? "settings" : "settings-outline";
              }

              // You can return any component that you like here!
              return <Ionicons name={iconName} size={size} color={color} />;
            },
          })}
          tabBarOptions={{
            activeTintColor: "tomato",
            inactiveTintColor: "grey",
            labelStyle: { paddingBottom: 10, fontSize: 10 },
            style: { padding: 10, height: 70 },
          }}
        >
          <Tab.Screen name={homeName} component={SeePostScreen} />
          <Tab.Screen name={detailsName} component={CreatePost} />
        </Tab.Navigator>
      </NavigationContainer>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "red",
    flexWrap: "wrap",

  },
  logoutContainer: {
    position: "absolute",
    left: "40%",
    top: "3%",
  },
  logoutText: {
    color: "black",
  },
});
export default Home;
