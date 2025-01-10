#pragma once

#include <imgui.h>
#include <rlImGui.h>

namespace qlexengine
{
    class GUI
    {
    public:
        void initialize() {}
        void start()
        {
            _log->msg("Starting rlImGui...");
            IMGUI_CHECKVERSION();
            rlImGuiSetup(false);
            _log->msg("Starting rlImGui Done");
        }
        void stop()
        {
            rlImGuiShutdown();
        }

        void render(const std::vector<std::shared_ptr<Shape2D>> &shapes_)
        {
            rlImGuiBegin();
            {
                ImGui::Begin("Helper - Data");

                if (ImGui::BeginTable("Shapes", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
                {
                    ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed);
                    ImGui::TableSetupColumn("position (x,y)", ImGuiTableColumnFlags_WidthStretch);
                    ImGui::TableSetupColumn("velocity (x,y)", ImGuiTableColumnFlags_WidthStretch);
                    ImGui::TableHeadersRow();
                    for (int row = 0; row < shapes_.size(); row++)
                    {
                        ImGui::TableNextColumn();
                        ImGui::Text("%d", row);
                        ImGui::TableNextColumn();
                        std::stringstream force_helper;
                        force_helper << shapes_.at(row)->getPosition();
                        ImGui::Text("%s", force_helper.str().c_str());
                        ImGui::TableNextColumn();
                        std::stringstream velocity_helper;
                        velocity_helper << shapes_.at(row)->velocity;
                        ImGui::Text("%s", velocity_helper.str().c_str());
                    }
                    ImGui::EndTable();
                }

                ImGui::End();
            }
            rlImGuiEnd();
        }

        Color ImGuiToRaylibColor(ImVec4 color)
        {
            unsigned int rgba = ImGui::ColorConvertFloat4ToU32(color);
            unsigned char r = (rgba >> 16) & 0xFF;
            unsigned char g = (rgba >> 8) & 0xFF;
            unsigned char b = rgba & 0xFF;
            unsigned char a = (rgba >> 24) & 0xFF;
            return {r, g, b, a};
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("GUI");
    };
}