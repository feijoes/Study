import { View, Text } from "react-native";

export default function App() {
  return (
    <View
      style={{
        backgroundColor: "white",
        flex: 1,
        flexDirection: "row",
        justifyContent: "center",
        alignItems: "center",
        flexWrap:"wrap"
      }}
    >
      <View
        style={{ backgroundColor: "dodgerblue", width: 100, height: 100 }}
      />
      <View style={{ backgroundColor: "tomato", width: 100, height: 100 }} />
      <View style={{ backgroundColor: "gold", width: 100, height: 100 }} />
      <View style={{ backgroundColor: "grey", width: 100, height: 100 }} />
      <View style={{ backgroundColor: "greenyellow", width: 100, height: 100 }} />
    </View>
  );
}
