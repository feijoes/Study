import { StyleSheet, ScrollView, View } from "react-native";
import React from "react";
import PostsTest from "../TestJson/PostsTest";
import {Post} from "../components/";
const SeePostScreen = () => {

  return (
    <View style={styles.container}>
      <ScrollView style={{bounces : false}}>
        <View>
          {PostsTest.map((POST) => <Post POST={POST} key={POST.Id} />)}
        </View>
      </ScrollView>
    </View>
  );
};

export default SeePostScreen;

const styles = StyleSheet.create({
  container: {
    width: 400,
    padding: 30,
    marginTop: 20,
    paddingTop: 30,
    marginLeft:-5,
  },
});
