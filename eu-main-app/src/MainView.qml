// Copyright, Burkhard Stubert (burkhard.stubert@embeddeduse.com)

import QtQuick

import EmUse.Models

Rectangle
{
    property MainViewModel viewModel: BusinessLogic.mainViewModel

    color: "#1800a3" // duke blue

    Column
    {
        Row
        {
            spacing: 8

            Text
            {
                id: rpmText
                width: 160
                height: 56
                text: viewModel.engineSpeed.valueString
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                color: "#ebf5ee" // mint cream
                font.pixelSize: 48
            }

            Text
            {
                id: rpmUnit
                anchors.baseline: rpmText.baseline
                text: viewModel.engineSpeed.unit
                color: "#ebf5ee"
                font.pixelSize: 24
            }
        }

        Row
        {
            spacing: 8

            Text
            {
                id: kphText
                width: 160
                height: 56
                text: viewModel.vehicleSpeed.valueString
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignVCenter
                color: "#ebf5ee" // mint cream
                font.pixelSize: 48
            }

            Text
            {
                anchors.baseline: kphText.baseline
                text: viewModel.vehicleSpeed.unit
                color: "#ebf5ee"
                font.pixelSize: 24
            }
        }
    }
}
