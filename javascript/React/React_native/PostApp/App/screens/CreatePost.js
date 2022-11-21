import { StyleSheet, Text, View } from 'react-native'
import React from 'react'

export default function CreatePost() {
  return (
    <View style={{ flex: 1, alignItems: 'center', justifyContent: 'center' }}>
            <Text
                onPress={() => alert('This is the "Home" screen.')}
                style={{ fontSize: 26, fontWeight: 'bold' }}>Home Screen</Text>
        </View>
  )
}

const styles = StyleSheet.create({})