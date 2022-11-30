import { StyleSheet } from "react-native";
import * as React from "react";
import SeePostScreen from "./SeePostScreen";
import CreatePost from "./CreatePost";
import Ionicons from "react-native-vector-icons/Ionicons";
import { NavigationContainer } from "@react-navigation/native";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";

const Tab = createBottomTabNavigator();
const homeName = "Home";
const detailsName = "Details";


const ScreensContainer = () => {
  return (
    <>
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
            tabBarActiveTintColor: "tomato",
            tabBarInactiveTintColor: "grey",
            tabBarLabelStyle: {
              paddingBottom: 10,
              fontSize: 10,
            },
            tabBarStyle: [
              {
                display: "flex",
              },
              null,
            ],
          })}
        >
          <Tab.Screen name={homeName} component={SeePostScreen} />
          <Tab.Screen name={detailsName} component={CreatePost} />
        </Tab.Navigator>
      </NavigationContainer>
    </>
  );
};

export default ScreensContainer;

const styles = StyleSheet.create({});
