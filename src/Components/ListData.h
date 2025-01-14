#pragma once

#include "helpers.h"
#include "ListDataItem.h"
#include <cstdint>
#include <string>
#include <map>
#include <vector>

class ListData
{
public:
    ListData() : id(0)
    {
    }

    explicit ListData(uint8_t newId) : id(newId)
    {
    }

    virtual ~ListData() = default;

    uint8_t getId(void) const
    {
        return (id);
    }

    void
        addItem(uint16_t value, const char *label, const char *bitmap = nullptr)
    {
        items.push_back(ListDataItem(value, label, bitmap));
    }

    ListDataItem getByIndex(uint16_t index) const
    {
        return (items[index]);
    }

    uint16_t getNumItems(void) const
    {
        return (items.size());
    }

    uint16_t getMaxIndex(void) const
    {
        return (getNumItems() - 1);
    }

    void print(void) const
    {
        logMessage("id: %d", getId());
        for (const auto &item : items) {
            logMessage(
                "    midiValue: %d, label: %s, bitmapEmpty: %d, address=%d",
                item.getValue(),
                item.getLabel(),
                item.isBitmapEmpty(),
                item.getAddress());
        }
    }

private:
    uint8_t id;
    std::vector<ListDataItem> items;
};
