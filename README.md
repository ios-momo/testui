# Cryptocurrency Exchange Mobile Application

## Overview

This is an iOS project that displays real-time order book and recent trade data for the XBTUSD pair using the BitMEX WebSocket API.

## Demo / Sample

Please check `screen_recording.mp4` for a demonstration.

## Features

* **Real-time Data**: Receives and updates the UI with order book (L2) and trade data in real-time via the BitMEX WebSocket API.
* **Tab Navigation**: Features two main tabs: 'Order Book' and 'Recent Trades'.
* **Order Book**:
    * Displays the top 20 Buy and 20 Sell orders, sorted by price.
    * Visualizes the relative size of orders using background bars.
    * Prices are displayed with one decimal place.
    * The entire content area is scrollable.
* **Recent Trades**:
    * Displays the 30 most recent trades.
    * Buy trades are shown in green text, Sell trades in red.
    * New trades are highlighted with a background color for 0.2 seconds (Green for Buy, Red for Sell).

## Technology Stack

* **Language**: Swift
* **UI Framework**: SwiftUI
* **Networking**: `URLSessionWebSocketTask`
    * Subscribes to topics by adding them as query parameters when connecting via WebSocket.
    * When the tab changed, it unsubscribes from the previous topic and subscribes to the new screen's topic.
    * Implements a ping/pong mechanism
        * A timer sends a `ping` 5 seconds after receiving any message. 
        * If a `pong` is not received within 5 seconds, it triggers a reconnection.
* **Asynchronous Processing**: Swift Concurrency, `swift-async-algorithms`(Chunks Operation)
* **Data Management**:
    * Order book data is managed using two main structures:
        * A `Dictionary` to store the relationship between order `ID` and `Price`.
        * Two `B+Tree` instances (one for Buy, one for Sell) to store `OrderBookItem`s, keyed by `Price`.
    * Since IDs are unique and BitMEX samples might lack price/size on delete operations, the `ID` is used to find the `Price` first, and then `insert`, `update`, or `delete` operations are performed on the B+Trees.
* **View Logic Cycle**:
    * Flow
        1. Actions are sent to the store from the view.
        2. Then the reducer updates the state and returns effects.
        3. The store then executes these effects, which can feed new actions back into the system.
    * Definition
        * Store
            * The runtime engine of the application.
            * Has the State, processes Actions, executes the Reducer, and manages Effects.
        * Reducer
            * Defines the core logic of the application.
            * Determines how the State changes in response to an Action and which Effects should be executed.
        * Effect
            * Represents side effects, such as asynchronous tasks or API calls.

## Why a B+Tree was Chosen

* Frequent Modifications: The order book data involves frequent insertions, updates, and deletions.
* Efficient Range Scans: B+Trees are particularly well-suited for efficient range scans.
* Performance: B+Trees offer O(log n) time complexity for these operations.
* Implementation Basis: Adapted from the B-Tree code in the Kodeco Swift Algorithm Club.
    * Reference: [B-Tree](https://github.com/kodecocodes/swift-algorithm-club/tree/master/B-Tree)

## How to Run

1.  Open `Flipster.xcodeproj` in Xcode.
2.  Select your target device or simulator.
3.  Choose `Product > Run` to build and run the application.
4.  Choose `Product > Test` to run the unit tests.
